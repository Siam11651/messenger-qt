#ifndef WEBENGINE_PROFILE_H
#define WEBENGINE_PROFILE_H

#include <QWebEngineProfile>

namespace messenger {
class webengine_profile : public QWebEngineProfile {
private slots:
  void handle_download_request(QWebEngineDownloadRequest *download);

public:
  webengine_profile(const QString &_name, QObject *_parent = nullptr);
  ~webengine_profile();
};
} // namespace messenger

#endif
