#ifndef WEBENGINE_VIEW_H
#define WEBENGINE_VIEW_H

#include <QWebEnginePage>
#include <QWebEngineView>

namespace messenger {
class webengine_view : public QWebEngineView {
public:
  webengine_view(const QString &_profile_name);
  ~webengine_view();
};
} // namespace messenger

#endif