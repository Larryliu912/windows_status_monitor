#define HAVE_REMOTE

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <pcap.h>
int main(int argc, char *argv[])
{
    pcap_if_t *alldevs;
      pcap_if_t *d;
      int i=0;
      char errbuf[PCAP_ERRBUF_SIZE];

      /* Retrieve the device list from the local machine */
      if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL /* auth is not needed */, &alldevs, errbuf) == -1)
      {
          fprintf(stderr,"Error in pcap_findalldevs_ex: %s\n", errbuf);
          exit(1);
      }

      /* Print the list */
      for(d= alldevs; d != NULL; d= d->next)
      {
          printf("%d. %s", ++i, d->name);
          if (d->description)
              printf(" (%s)\n", d->description);
          else
              printf(" (No description available)\n");
      }

      if (i == 0)
      {
          printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
      }

      /* We don't need any more the device list. Free it */
      pcap_freealldevs(alldevs);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
