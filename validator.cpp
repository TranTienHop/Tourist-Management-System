#include "validator.h"

bool input_validator::kiemTraSDT(const string& sdt) {
	if (sdt.length() != 10) return false;
    if (sdt[0] != '0') return false;

    for (char c : sdt) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool input_validator::kiemTraEmail(const string& email) {
	if (email.empty()) return false;
    if (email.find(' ') != string::npos) return false;

    size_t at = email.find('@');
    size_t dot = email.find('.', at + 1);

    return (at != string::npos && dot != string::npos && dot > at + 1);
}


