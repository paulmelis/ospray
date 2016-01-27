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

#include "sg/common/Common.h"

namespace ospray {
  namespace viewer {

    /*! small helper class to compute (smoothed) frames-per-second values */
    struct FPSCounter 
    {
      FPSCounter();
      void startRender();
      void doneRender();
      double getSmoothFPS() const;
      double getFPS() const;

    private:
      double fps;
      double smooth_nom;
      double smooth_den;
      double frameStartTime;
    };

  } // ::ospray::viewer
} // ::ospray
