#ifndef WEBENGINE_VIEW_H
#define WEBENGINE_VIEW_H

#include <QWebEnginePage>
#include <QWebEngineView>
#include <messenger/ui/webengine_profile.hpp>

namespace messenger {
class webengine_view : public QWebEngineView {
private:
  messenger::webengine_profile *m_webengine_profile;

public:
  webengine_view(const QString &_profile_name);
  messenger::webengine_profile *profile() const;
  ~webengine_view();
};
} // namespace messenger

#endif