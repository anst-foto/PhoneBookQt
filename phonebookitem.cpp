#include "phonebookitem.h"

PhoneBookItem::PhoneBookItem(const QString &name, const QString &phone) {
    _name = name;
    _phone = phone;
}
PhoneBookItem::~PhoneBookItem() {}

const QString &PhoneBookItem::getName() const {
    return _name;
}
void PhoneBookItem::setName(const QString &name) {
    if (name != _name) {
        _name = name;
    }
}

const QString &PhoneBookItem::getPhone() const {
    return _phone;
}
void PhoneBookItem::setPhone(const QString &phone) {
    if (phone != _phone) {
        _phone = phone;
    }
}
