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

#ifndef tst_QVERSITCONTACTEXPORTER_H
#define tst_QVERSITCONTACTEXPORTER_H

#include <qcontactdetail.h>
#include <QObject>
#include <qcontact.h>
#include <qversitproperty.h>

QTPIM_BEGIN_NAMESPACE
class QVersitContactExporter;
class QVersitContactExporterPrivate;
class QVersitDocument;
class QVersitProperty;
class MyQVersitResourceHandler;
class MyQVersitContactExporterDetailHandler;
QTPIM_END_NAMESPACE

QTPIM_USE_NAMESPACE

class tst_QVersitContactExporter : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();

    void testConvertContact();
    void testEmptyContact();
    void testContactDetailHandler();
    void testContactDetailHandlerV2();
    void testEncodeName();
    void testEncodePhoneNumber();
    void testEncodeEmailAddress();
    void testEncodeStreetAddress();
    void testEncodeUrl();
    void testEncodeParameters();
    void testEncodeUid();
    void testEncodeRev();
    void testEncodeBirthDay();
    void testEncodeNote();
    void testEncodeGeoLocation();
    void testEncodeOrganization();
    void testEncodeEmbeddedContent();
    void testEncodeRingtone();
    void testEncodeGender();
    void testEncodeNickName();
    void testEncodeTag();
    void testEncodeAnniversary();
    void testEncodeOnlineAccount();
    void testEncodeFamily();
    void testEncodeAvatar();
    void testEncodeThumbnail();
    void testDefaultResourceHandler();

private:
    // Test Utility Functions
    QContact createContactWithName(QString name);
    int countProperties(const QVersitDocument& document);
    QContactDetail findDetailByName(QList<QContactDetail> details, QString search);
    QVersitProperty findPropertyByName(const QVersitDocument& document,const QString& propertyName);

private: // Data
    QVersitContactExporter* mExporter;
    MyQVersitResourceHandler* mResourceHandler;
};

#endif // tst_QVERSITCONTACTEXPORTER_H
