#include "customer.h"

Customer::Customer() : customer_id(""), number_of_people(0), total_spending(0.0) {}
Customer::Customer(string id, string nameStr, int mobile, string dobStr, string email, int num, double total) {
	customer_id = id;
	number_of_people = num;
	total_spending = total;

	CName n;
	n.set_fullname(nameStr, "", "");  // lưu nguyên fullname
	set_name(n);

	CDate d;
	d.parse_date(dobStr);
	set_dob(d);

	set_mobile(mobile);
	set_email(email);
}
Customer::Customer(const Customer& c) {
	customer_id = c.customer_id;
	number_of_people = c.number_of_people;
	total_spending = c.total_spending;
	name = c.name;
	dob = c.dob;
	mobile = c.mobile;
	email = c.email;
}
Customer::~Customer() {}

void Customer::set_customer_id(string id) { customer_id = id; }
void Customer::set_number_of_people(int n) { number_of_people = n; }
void Customer::set_total_spending(double s) { total_spending = s; }

string Customer::get_customer_id() { return customer_id; }
int Customer::get_number_of_people() { return number_of_people; }
double Customer::get_total_spending() { return total_spending; }

// -------------------- Input / Display --------------------
void Customer::input() {
	cout << "Nhap ma khach hang: ";
	getline(cin, customer_id);

	cout << "Nhap ho ten: ";
	string fullname; getline(cin, fullname);
	CName n; n.set_fullname(fullname, "", "");
	set_name(n);

	cout << "Nhap so dien thoai: ";
	int m; cin >> m; cin.ignore();
	set_mobile(m);

	cout << "Nhap ngay sinh (dd/mm/yyyy): ";
	string dobStr; getline(cin, dobStr);
	CDate d; d.parse_date(dobStr);
	set_dob(d);

	cout << "Nhap email: ";
	string e; getline(cin, e);
	set_email(e);

	cout << "Nhap so nguoi di cung: ";
	int num; cin >> num; cin.ignore();
	set_number_of_people(num);

	cout << "Nhap tong chi tieu: ";
	double total; cin >> total; cin.ignore();
	set_total_spending(total);
}

void Customer::display() {
	cout << "| " << setw(10) << customer_id
		<< " | " << setw(29) << get_name().get_fullname()
		<< " | " << setw(12) << mobile
		<< " | " << setw(10) << dob.to_string()
		<< " | " << setw(20) << email
		<< " | " << setw(11) << number_of_people
		<< " | " << setw(10) << fixed << setprecision(0) << total_spending
		<< " |\n";
}

// -------------------- Override các hàm ảo --------------------
void Customer::update() {
	cout << "Cap nhat thong tin khach hang ma " << customer_id << endl;
	cout << "Nhap so nguoi moi: "; int n; cin >> n; cin.ignore(); set_number_of_people(n);
	cout << "Nhap tong chi tieu moi: "; double t; cin >> t; cin.ignore(); set_total_spending(t);
}

void Customer::edit() {
	cout << "Chinh sua thong tin khach hang ma " << customer_id << endl;
	cout << "Nhap ma moi (neu muon giu nguyen nhan ENTER): "; string id; getline(cin, id);
	if (!id.empty()) set_customer_id(id);

	cout << "Nhap so nguoi di cung moi: "; int n; cin >> n; cin.ignore(); set_number_of_people(n);
	cout << "Nhap tong chi tieu moi: "; double t; cin >> t; cin.ignore(); set_total_spending(t);
}

void Customer::remove() {
	cout << "Da xoa khach hang ma: " << customer_id << endl;
	customer_id = "";
	number_of_people = 0;
	total_spending = 0;
}

void Customer::save() {
	ofstream fout("customer.txt", ios::app);
	if (fout.is_open()) {
		fout << customer_id << "," << get_name().get_fullname() << "," << get_mobile() << ","
			<< get_dob().to_string() << "," << get_email() << "," << number_of_people << ","
			<< total_spending << endl;
		fout.close();
	}
	else {
		cout << "Khong the mo file de luu!" << endl;
	}
}

// -------------------- Chức năng bổ sung --------------------
void Customer::calculate_loyalty_points() {
	cout << "Tinh diem khach hang cho ma: " << customer_id << endl;
}

void Customer::view_booking() {
	cout << "Xem lich dat cho khach hang ma: " << customer_id << endl;
}


CustomerList::CustomerList() { head = nullptr; }
CustomerList::~CustomerList() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
bool CustomerList::isEmpty() { return head == nullptr; }

void CustomerList::add_customer(const Customer& c) {
	Node* p = new Node{ c, nullptr };
	if (head == nullptr) head = p;
	else {
		Node* temp = head;
		while (temp->next) temp = temp->next;
		temp->next = p;
	}
}
void CustomerList::update_customer(string id) {
	Node* found = search_by_id(id);
	if (found) {
		found->data.update();  // gọi hàm update của Customer
	}
	else {
		cout << "Khong tim thay khach hang voi ID: " << id << endl;
	}
}

void CustomerList::display_all() {
	if (isEmpty()) {
		cout << "Danh sach rong.\n";
		return;
	}

	cout << "+------------+-------------------------------+--------------+------------+----------------------+-------------+------------+\n";
	cout << "|   ID       |           Ho ten              |    SDT       | Ngay sinh  | Email                | So nguoi    | Tong tien  |\n";
	cout << "+------------+-------------------------------+--------------+------------+----------------------+-------------+------------+\n";

	Node* temp = head;
	while (temp) {
		temp->data.display();
		temp = temp->next;
	}

	cout << "+------------+-------------------------------+--------------+------------+----------------------+-------------+------------+\n";
}


Node* CustomerList::search_by_id(string id) {
	Node* temp = head;
	while (temp) {
		if (temp->data.get_customer_id() == id)
			return temp;
		temp = temp->next;
	}
	return nullptr;
}

void CustomerList::remove_customer(string id) {
	if (isEmpty()) return;
	if (head->data.get_customer_id() == id) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	Node* prev = head;
	Node* curr = head->next;
	while (curr) {
		if (curr->data.get_customer_id() == id) {
			prev->next = curr->next;
			delete curr;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

void CustomerList::save_to_file(string filename) {
	ofstream fout(filename);
	Node* temp = head;
	while (temp) {
		fout << temp->data.get_customer_id() << ","
			<< temp->data.get_number_of_people() << ","
			<< temp->data.get_total_spending() << endl;
		temp = temp->next;
	}
	fout.close();
}

void CustomerList::load_from_file(string filename) {
	ifstream fin(filename);
	if (!fin.is_open()) return;

	string line;
	while (getline(fin, line)) {
		stringstream ss(line);
		string id, fullname, date, email;
		int mobile, num;
		double total;

		getline(ss, id, ',');
		getline(ss, fullname, ',');
		string mobile_str;
		getline(ss, mobile_str, ',');
		mobile = stoi(mobile_str);
		getline(ss, date, ',');
		getline(ss, email, ',');
		string num_str;
		getline(ss, num_str, ',');
		num = stoi(num_str);
		string total_str;
		getline(ss, total_str, ',');
		total = stod(total_str);

		CName n;
		n.set_fullname(fullname, "", "");  // không tách, lưu nguyên fullname

		CDate d;
		d.parse_date(date);

		Customer c;
		c.set_customer_id(id);
		c.set_name(n);
		c.set_dob(d);
		c.set_email(email);
		c.set_mobile(mobile);
		c.set_number_of_people(num);
		c.set_total_spending(total);

		add_customer(c);
	}

	fin.close();
}

