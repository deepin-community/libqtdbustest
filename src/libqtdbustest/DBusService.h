/*
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of version 3 of the GNU Lesser General Public License as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Pete Woods <pete.woods@canonical.com>
 */

#ifndef QTDBUSTEST_DBUSSERVICE_H_
#define QTDBUSTEST_DBUSSERVICE_H_

#include <QDBusConnection>
#include <QSharedPointer>
#include <QScopedPointer>

namespace QtDBusTest {

class DBusService;
class DBusServicePrivate;

typedef QSharedPointer<DBusService> DBusServicePtr;

class Q_DECL_EXPORT DBusService {
public:
	DBusService(const QString &name, QDBusConnection::BusType busType);

	virtual ~DBusService();

	virtual const QString & name() const;

	virtual QDBusConnection::BusType busType() const;

	virtual void start(const QDBusConnection &connection) = 0;

private:
	QScopedPointer<DBusServicePrivate> d;
};

}

#endif /* QTDBUSTEST_DBUSSERVICE_H_ */
