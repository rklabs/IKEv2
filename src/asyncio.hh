/*
 * Copyright (C) 2014 Raju Kadam <rajulkadam@gmail.com>
 *
 * IKEv2 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * IKEv2 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <string.h>  // memset
#include <unistd.h>  // close
#include <sys/epoll.h>

#include <memory> // std::shared_ptr
#include <vector>
#include <algorithm> // std::find_if

#include "logging.hh"

namespace ASIO {

class AsyncIOHandler {
 public:
    using epollEventPtr = std::shared_ptr<struct epoll_event>;
    AsyncIOHandler(S32 noOfEvents, std::string pollerName);
    S32 createPoller();
    S32 addFd(S32 fd);
    S32 removeFd(S32 fd);
    S32 modifyFd(S32 fd, S32 op);
    S32 watchFds();
    void shutdownHandler();
    ~AsyncIOHandler();

    const S32 EPOLL_BLOCK_FD = -1;
 private:
    S32 epollFd_;
    S32 maxEvents_;
    bool stopPoller_;
    std::string name_;
    std::vector<epollEventPtr> watchedEvents_;
};

}  // namespace ASIO
