#define HAVE_REMOTE

#include "speed.h"
#include<string>
#include<pcap.h>
using namespace std;

Speed::Speed()
{


}

void Speed::updateInfo(){
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
          return;
      }

      /* We don't need any more the device list. Free it */
      pcap_freealldevs(alldevs);
}

void Speed::getDevs(){

}


Speed::~Speed()
{


}
