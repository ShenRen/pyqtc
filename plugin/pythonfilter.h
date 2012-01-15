/* This file is part of Clementine.
   Copyright 2011, David Sansome <me@davidsansome.com>
   
   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PYQTC_PYTHONFILTER_H
#define PYQTC_PYTHONFILTER_H

#include <locator/ilocatorfilter.h>

#include "workerclient.h"
#include "workerpool.h"

namespace pyqtc {

class PythonIcons;

class PythonFilter : public Locator::ILocatorFilter {
public:
  PythonFilter(WorkerPool<WorkerClient>* worker_pool,
               const PythonIcons* icons);

  QString displayName() const { return tr("Python symbols"); }
  QString id() const { return "Python symbols"; }
  Priority priority() const { return Medium; }

  QList<Locator::FilterEntry> matchesFor(
      QFutureInterface<Locator::FilterEntry>& future, const QString& entry);
  void accept(Locator::FilterEntry selection) const;
  void refresh(QFutureInterface<void>& future);

  struct EntryInternalData {
    EntryInternalData(const QString& file_path = QString(), int line_number = 0)
      : file_path_(file_path),
        line_number_(line_number)
    {}

    QString file_path_;
    int line_number_;
  };

private:
  WorkerPool<WorkerClient>* worker_pool_;
  const PythonIcons* icons_;
};

} // namespace pyqtc

Q_DECLARE_METATYPE(pyqtc::PythonFilter::EntryInternalData)

#endif // PYQTC_PYTHONFILTER_H
