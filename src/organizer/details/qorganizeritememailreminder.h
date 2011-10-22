/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef QORGANIZERITEMEMAILREMINDER_H
#define QORGANIZERITEMEMAILREMINDER_H

#include "qorganizeritemreminder.h"

QTORGANIZER_BEGIN_NAMESPACE

/* Leaf class */
class Q_ORGANIZER_EXPORT QOrganizerItemEmailReminder : public QOrganizerItemReminder
{
public:
    Q_DECLARE_CUSTOM_ORGANIZER_REMINDER_DETAIL(QOrganizerItemEmailReminder, "EmailReminder")
    const static QString FieldSubject;
    const static QString FieldBody;
    const static QString FieldAttachments;
    const static QString FieldRecipients;

    // email data if email notification.
    void setContents(const QString& subject, const QString& body, const QVariantList& attachments) {setValue(FieldSubject, subject); setValue(FieldBody, body); setValue(FieldAttachments, attachments);}
    QString subject() const {return value(FieldSubject).toString();}
    QString body() const {return value(FieldBody).toString();}
    QVariantList attachments() const {return value<QVariantList>(FieldAttachments);} // mime data type?
    void setRecipients(const QStringList& recipients) {setValue(FieldRecipients, recipients);}
    QStringList recipients() const {return value<QStringList>(FieldRecipients);}
};

QTORGANIZER_END_NAMESPACE

#endif

