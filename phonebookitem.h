#ifndef PHONEBOOKITEM_H
#define PHONEBOOKITEM_H

#include <QString>

class PhoneBookItem
{
private:
    QString _name;
    QString _phone;

public:
    PhoneBookItem(const QString &name, const QString &phone);
    ~PhoneBookItem();

    const QString &getName() const;
    void setName(const QString &name);

    const QString &getPhone() const;
    void setPhone(const QString &phone);
};

#endif // PHONEBOOKITEM_H
