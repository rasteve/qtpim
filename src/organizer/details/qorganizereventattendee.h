/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef QORGANIZEREVENTATTENDEE_H
#define QORGANIZEREVENTATTENDEE_H

#include <QString>
#include <qorganizeritemdetail.h>

QTORGANIZER_BEGIN_NAMESPACE

class Q_ORGANIZER_EXPORT QOrganizerEventAttendee : public QOrganizerItemDetail
{
public:
    Q_DECLARE_CUSTOM_ORGANIZER_DETAIL(QOrganizerEventAttendee, "Attendee")
    const static QString FieldName;
    const static QString FieldEmailAddress;
    const static QString FieldContactId;
    const static QString FieldParticipationStatus;
    const static QString FieldParticipationRole;

    enum ParticipationStatus {
        StatusUnknown = 0,
        StatusAccepted,
        StatusDeclined,
        StatusTentative,
        StatusDelegated,
        StatusInProcess,
        StatusCompleted
    };

    enum ParticipationRole {
        RoleUnknown = 0,
        RoleOrganizer,
        RoleChairperson,
        RoleHost,
        RoleRequiredParticipant,
        RoleOptionalParticipant,
        RoleNonParticipant
    };

    void setName(const QString &name);
    QString name() const;

    void setEmailAddress(const QString &emailAddress);
    QString emailAddress() const;

    void setParticipationStatus(ParticipationStatus status);
    ParticipationStatus participationStatus() const;

    void setParticipationRole(ParticipationRole role);
    ParticipationRole participationRole() const;

    void setContactId(const QString &contactId);
    QString contactId() const;
};

QTORGANIZER_END_NAMESPACE

#endif