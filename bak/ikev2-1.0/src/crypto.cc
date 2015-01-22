/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
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

#include "crypto.hh"

namespace Crypto {
Cipher::Cipher() {
    TRACE();
}

Cipher::~Cipher() {
    TRACE();
}

Hash::Hash() {
    TRACE();
}

Hash::~Hash() {
    TRACE();
}

Hmac::Hmac() {
    TRACE();
}

Hmac::~Hmac() {
    TRACE();
}

DH::DH() {
    TRACE();
}

DH::~DH() {
    TRACE();
}

CryptoPluginInterface::CryptoPluginInterface() {
    TRACE();
}

CryptoPluginInterface::~CryptoPluginInterface() {
    TRACE();
}

OpensslPlugin::OpensslPlugin() {
    TRACE();
}

OpensslPlugin::~OpensslPlugin() {
    TRACE();
}

CryptoppPlugin::CryptoppPlugin() {
    TRACE();
}

CryptoppPlugin::~CryptoppPlugin() {
    TRACE();
}

void OpensslPlugin::init() {
    TRACE();
}

void CryptoppPlugin::init() {
    TRACE();
}
}  // namespace crypto
