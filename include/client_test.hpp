#include <standalone_asio.hpp>

using namespace asio::ip;

void client()
{
    asio::io_service io;
    tcp::endpoint ep(address::from_string("127.0.0.1"), 22334);
    tcp::socket socket(io);
    socket.connect(ep);
    asio::error_code err;
    char buf[512] = { 0 };
    for (;;)
    {
        std::size_t len = socket.read_some(asio::buffer(buf), err);
        std::cout.write(buf, len);
    }
}