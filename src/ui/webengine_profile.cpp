#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QWebEngineDownloadRequest>
#include <messenger/ui/webengine_profile.hpp>

void messenger::webengine_profile::handle_download_request(
    QWebEngineDownloadRequest *download) {
  QFileDialog file_dialog;

  file_dialog.setMimeTypeFilters({download->mimeType()});
  file_dialog.setAcceptMode(QFileDialog::AcceptMode::AcceptSave);
  file_dialog.selectFile(download->suggestedFileName());

  const int32_t file_status = file_dialog.exec();

  if(file_status == QDialog::DialogCode::Accepted) {
    download->setDownloadFileName(file_dialog.selectedFiles().first());
    download->accept();
  }
}

messenger::webengine_profile::webengine_profile(const QString &_name)
    : QWebEngineProfile(_name) {
  setPersistentCookiesPolicy(
      QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
  setPersistentStoragePath(
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) +
      "/webview-data");

  connect(this, &messenger::webengine_profile::downloadRequested, this,
          &messenger::webengine_profile::handle_download_request);
}

messenger::webengine_profile::~webengine_profile() {}