// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Calculator.h"

#include <thrift/config.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>

#include <iostream>

using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

class CalculatorHandler : virtual public CalculatorIf {
 public:
  CalculatorHandler()
  {
  }

  int64_t add(const int32_t num1, const int32_t num2)
  {
    return 0;
  }

};

int main(int argc, char **argv) {
    int port = 9090;
    std::shared_ptr<CalculatorHandler> handler(new CalculatorHandler());
    std::shared_ptr<TProcessor> processor(new CalculatorProcessor(handler));
    std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());


    TSimpleServer server1(processor, serverTransport, transportFactory, protocolFactory);
    TThreadedServer server2(processor, serverTransport, transportFactory, protocolFactory);
    TThreadPoolServer server3(processor, serverTransport, transportFactory, protocolFactory);

    const int workerCount = 4;
    std::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(workerCount);
    threadManager->threadFactory(std::make_shared<ThreadFactory>());

    std::cout << "Thrift " << PACKAGE_VERSION << '\n';
    return EXIT_SUCCESS;
}