#ifndef PYQTC_PLUGIN_H
#define PYQTC_PLUGIN_H

#include <extensionsystem/iplugin.h>

namespace pyqtc {

class Plugin : public ExtensionSystem::IPlugin {
  Q_OBJECT

public:
  Plugin();
  ~Plugin();

  bool initialize(const QStringList& arguments, QString* errorString);
  void extensionsInitialized();
  ShutdownFlag aboutToShutdown();
};

} // namespace pyqtc

#endif // PYQTC_PLUGIN_H

