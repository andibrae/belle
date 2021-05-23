/*
  ==============================================================================

  Copyright 2007-2013, 2017 Andi Brae
  Copyright 2013-2016 Robert Taub

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

  ==============================================================================
*/

#define PRIM_WITH_TIMER
#define PRIM_COMPILE_INLINE
#include "prim.h"
using namespace prim;

int main()
{
  Tree<String> T;
  T["Hello"] = "World";
  T["Foo"] = "Bar";

  C::Out() >> T.Contains("Hello");
  C::Out() >> T.Contains("What");
  C::Out() >> T.First();
  C::Out() >> T.Last();
  C::Out() >> T["Foo"];
  C::Out() >> T.n();
  C::Out() >> T["Hello"];
  T["Hello"] = "there";
  C::Out() >> T["Hello"];

  Tree<String>::Iterator It;
  for(It.Begin(T); It.Iterating(); It.Next())
    C::Out() >> It.Key() << " = " << It.Value();

  return AutoRelease<Console>();
}
