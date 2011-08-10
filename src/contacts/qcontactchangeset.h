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


#ifndef QCONTACTCHANGESET_H
#define QCONTACTCHANGESET_H

#include "qtcontactsglobal.h"
#include "qcontactid.h"

#include <QSet>
#include <QPair>
#include <QSharedDataPointer>

QTPIM_BEGIN_NAMESPACE

class QContactManagerEngine;
class QContactChangeSetData;
class Q_CONTACTS_EXPORT QContactChangeSet
{
public:
    QContactChangeSet();
    QContactChangeSet(const QContactChangeSet& other);
    ~QContactChangeSet();

    QContactChangeSet& operator=(const QContactChangeSet& other);

    void setDataChanged(bool dataChanged);
    bool dataChanged();

    QSet<QContactLocalId> addedContacts() const;
    void insertAddedContact(QContactLocalId addedContactId);
    void insertAddedContacts(const QList<QContactLocalId>& addedContactIds);
    void clearAddedContacts();

    QSet<QContactLocalId> changedContacts() const;
    void insertChangedContact(QContactLocalId addedContactId);
    void insertChangedContacts(const QList<QContactLocalId>& addedContactIds);
    void clearChangedContacts();

    QSet<QContactLocalId> removedContacts() const;
    void insertRemovedContact(QContactLocalId addedContactId);
    void insertRemovedContacts(const QList<QContactLocalId>& addedContactIds);
    void clearRemovedContacts();

    QSet<QContactLocalId> addedRelationshipsContacts() const;
    void insertAddedRelationshipsContact(QContactLocalId affectedContactId);
    void insertAddedRelationshipsContacts(const QList<QContactLocalId>& affectedContactIds);
    void clearAddedRelationshipsContacts();

    QSet<QContactLocalId> removedRelationshipsContacts() const;
    void insertRemovedRelationshipsContact(QContactLocalId affectedContactId);
    void insertRemovedRelationshipsContacts(const QList<QContactLocalId>& affectedContactIds);
    void clearRemovedRelationshipsContacts();

    void setOldAndNewSelfContactId(const QPair<QContactLocalId, QContactLocalId>& oldAndNewContactId);
    QPair<QContactLocalId, QContactLocalId> oldAndNewSelfContactId() const;

    void clearAll();

    void emitSignals(QContactManagerEngine *engine);

private:
    QSharedDataPointer<QContactChangeSetData> d;
};

QTPIM_END_NAMESPACE

#endif
