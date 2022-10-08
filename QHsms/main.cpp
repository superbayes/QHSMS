#include "dialog.h"
#include <QApplication>

Dialog *pDialog = nullptr;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
  {
      QByteArray localMsg = msg.toLocal8Bit();
      switch (type) {
      case QtDebugMsg:
          pDialog->log("Debug: " + msg);
          //fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
          break;
      case QtInfoMsg:
          pDialog->log("Info: " + msg);
          //fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
          break;
      case QtWarningMsg:
          pDialog->log("Warning: " + msg);
          //fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
          break;
      default:
          break;
      }
  }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    Dialog w;
    pDialog = &w;
    qInstallMessageHandler(myMessageOutput);
    w.show();

    return a.exec();
}
