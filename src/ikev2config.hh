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

#include <unistd.h>
#include <limits.h>
#include <sys/inotify.h>
#include <sys/stat.h>   // open

#include "logging.hh"
#include "threadpool.hh"
#include "synchro.hh"
#include "asyncio.hh"
#include "utils.hh"

namespace IKEv2 {

#define IKEV2_CONF_FILE "ikev2.conf"

class Config {
 public:
    Config();
    ~Config();
    int confFilePresent();
    int confFileWatcher();
    void shutdown();
    Synchro::Notifier & eventNotifier();
    static const int STOP_CFG_THREAD = 1;
    // Max events which poller needs to handle
    // C++11 only
    const int CFG_MAX_EVENTS = 3;
    const int EVENT_SIZE = sizeof(struct inotify_event);
    const int INOTIFY_BUFFER_LEN = (CFG_MAX_EVENTS + 1)* EVENT_SIZE;
    const int INODE_EVENTS = IN_MODIFY | IN_CREATE | IN_DELETE;
 private:
    int inotifyFd_;
    int inotifyWd_;
    int eventFd_;
    bool stopThread_; // Tell ConfFileWatcher thread to stop
    Synchro::Notifier eventNotifier_;
    ASIO::AsyncIOHandler asioHdl_;
};

}  // namespace IKEv2
