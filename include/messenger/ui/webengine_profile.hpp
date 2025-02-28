#ifndef WEBENGINE_PROFILE_H
#define WEBENGINE_PROFILE_H

#include <QWebEngineProfile>

namespace messenger {
class webengine_profile : public QWebEngineProfile {
public:
  webengine_profile(const QString &_name);
  ~webengine_profile();
};
} // namespace messenger

#endif