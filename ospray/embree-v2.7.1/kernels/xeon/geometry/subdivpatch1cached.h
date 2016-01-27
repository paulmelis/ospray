// ======================================================================== //
// Copyright 2009-2016 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "../geometry/primitive.h"
#include "../../common/subdiv/subdivpatch1base.h"

namespace embree
{

  struct __aligned(64) SubdivPatch1Cached : public SubdivPatch1Base
  {
    struct Type : public PrimitiveType 
    {
      Type ();
      size_t size(const char* This) const;
    };
    
    static Type type;

  public:

    /*! constructor for cached subdiv patch */
    SubdivPatch1Cached (const unsigned int gID,
                        const unsigned int pID,
                        const unsigned int subPatch,
                        const SubdivMesh *const mesh,
                        const Vec2f uv[4],
                        const float edge_level[4],
                        const int subdiv[4],
                        const int simd_width) 
      : SubdivPatch1Base(gID,pID,subPatch,mesh,uv,edge_level,subdiv,simd_width) {}
  };


  struct SubdivPatch1Eager 
  {
    struct Type : public PrimitiveType 
    {
      Type ();
      size_t size(const char* This) const;
      size_t blocks(size_t x) const { return x; }
    };
    
    static Type type;

  public:
    SubdivPatch1Eager() {}
  };


}
