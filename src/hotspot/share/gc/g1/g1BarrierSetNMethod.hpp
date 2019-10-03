/*
 * Copyright (c) 2019, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_GC_G1_G1BARRIERSETNMETHOD_HPP
#define SHARE_GC_G1_G1BARRIERSETNMETHOD_HPP

#include "gc/shared/barrierSetNMethod.hpp"

class G1BarrierSetNMethod : public BarrierSetNMethod {
  int _current_phase;

protected:
  virtual int disarmed_value() const;
  virtual bool nmethod_entry_barrier(nmethod* nm);

public:
  G1BarrierSetNMethod() : _current_phase(1) { }
  virtual ByteSize thread_disarmed_offset() const;
  void arm_all_nmethods();
};

#endif // SHARE_GC_G1_G1BARRIERSETNMETHOD_HPP
