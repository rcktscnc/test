#ifndef __CONNECTION_POOL_HPP__
#define __CONNECTION_POOL_HPP__

#include <connection.hpp>
#include <async_message.hpp>
#include <string>
#include <set>
#include <vector>
#include <utility>

class connection_pool
{
public:
    connection_pool(asio::io_service& io_service);
    void add(connection::ptr&& connection);
    void remove(const connection::ptr& connection);
    void broadcast(const async_message::shared_ptr& message);
    void send(const async_message::shared_ptr& message, std::size_t connection_id);
    void list_connections();

private:
    using _pair_t = std::pair<std::size_t, connection::ptr>;
    asio::strand _container_strand;
    std::vector<_pair_t> _connections;
    std::size_t _connection_id = 0;
};

#endif // __CONNECTION_POOL_HPP__