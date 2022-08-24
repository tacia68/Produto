#include "hello_daemon_cpp.h"

using namespace std;                    // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::hello {            // Entra no pacote devtitans::hello

void HelloDaemonCpp::startDaemon() {    // Implementa o método printHello da classe HelloCpp
    ALOG(LOG_INFO, "DevTITANS", "Daemon Hello iniciando ...");

    int count = 1;

    string filename = string("/proc/version");      // Abrindo o arquivo version em /proc
    ifstream file = ifstream(filename, ios_base::in);

    if(file.is_open() && file.good()){
        ALOG(LOG_INFO, "DevTITANS", "Conseguimos abrir e ler o arquivo.");
        file.close();
    }
    else{
        ALOG(LOG_INFO, "DevTITANS", "Não conseguimos abrir e nem ler o arquivo.");
    }

    while (true) {

        // Implemente aqui o serviço

        ALOG(LOG_INFO, "DevTITANS", "Daemon Hello World loop %d", count++);
        sleep(20);
    }

    // Nunca deve chegar aqui ...
}

} // namespace


using namespace devtitans::hello;       // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main() {
    HelloDaemonCpp daemon;              // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    daemon.startDaemon();               // Executa o método printHello
    // Nunca deve chegar aqui ...
    return 0;
}
