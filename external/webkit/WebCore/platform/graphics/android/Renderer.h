/*
* Copyright (c) 2011, Code Aurora Forum. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above
*       copyright notice, this list of conditions and the following
*       disclaimer in the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Code Aurora Forum, Inc. nor the names of its
*       contributors may be used to endorse or promote products derived
*       from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#if ENABLE(ACCELERATED_SCROLLING)

#ifndef WTF_Renderer_h
#define WTF_Renderer_h

#include "IntRect.h"
#include "PictureSet.h"
#include "SkBitmap.h"
#include "SkRect.h"
#include <wtf/HashSet.h>
#include <wtf/MessageQueue.h>
#include <wtf/PassOwnPtr.h>
#include <wtf/Threading.h>
#include <wtf/Vector.h>

namespace android {

class Renderer : public Noncopyable {
public:
    // WebViewCore lifetime is guaranteed, so can use raw pointer
    static Renderer* createRenderer();
	virtual ~Renderer() {};
    virtual void release() = 0;
    virtual void setContent(const PictureSet&, SkRegion*, bool) = 0;
    virtual void clearContent() = 0;
    virtual void pause() = 0;
    virtual void finish() = 0;
    virtual bool drawContent(SkCanvas*, SkColor, bool, PictureSet&, bool&) = 0;
    virtual void setContent(const SkPicture*, WebCore::IntRect&) = 0;
#if ENABLE(GPU_ACCELERATED_SCROLLING)
    virtual bool drawContentGL(PictureSet&, WebCore::IntRect&, SkRect&, float, SkColor color = SK_ColorWHITE) = 0;
#endif

};

} // namespace android

#endif // WTF_Renderer_h
#endif // ACCELERATED_SCROLLING
