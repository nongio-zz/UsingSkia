#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkImageEncoder.h"
#include "SkString.h"
#include "SkTemplates.h"
#include "SkTypeface.h"

// g++ main.cpp -Wl,-rpath,./ -L. -lskia -Iinclude/core -Iinclude/config -Iinclude/images -lpthread -lfreetype -lpng -o main

int main (int argc, char * const argv[]) {

    //
    SkAutoGraphics ag;

    //Output filename
    SkString path("skhello.png");

    //Set Text To Draw
    SkString text("Hydra v0.0.1a");

    SkPaint paint;

    //Set Text ARGB Color
    paint.setARGB(255, 255, 255, 255);

    //Turn AntiAliasing On
    paint.setAntiAlias(true);
    paint.setLCDRenderText(true);
    paint.setTypeface(SkTypeface::CreateFromName("sans-serif", SkTypeface::kNormal));

    //Set Text Size
    paint.setTextSize(SkIntToScalar(40));

    //Set Image Width & Height
    int width = 500;
    int height = 600;

    SkBitmap bitmap;
    bitmap.setConfig(SkBitmap::kARGB_8888_Config, width, height);
    bitmap.allocPixels();

    //Create Canvas
    SkCanvas canvas(bitmap);
    canvas.drawARGB(255, 25, 25, 25);

    //Text X, Y Position Varibles
    int x = 80;
    int y = 60;

    canvas.drawText(text.c_str(), text.size(), x, y, paint);

    //Set Style and Stroke Width
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(3);

    //Draw A Rectangle
    SkRect rect;
    paint.setARGB(255, 255, 255, 255);
    //Left, Top, Right, Bottom
    rect.set(50, 100, 200, 200);
    canvas.drawRoundRect(rect, 20, 20, paint);

    canvas.drawOval(rect, paint);

    //Draw A Line
    canvas.drawLine(10, 300, 300, 300, paint);

    //Draw Circle (X, Y, Size, Paint)
    canvas.drawCircle(100, 400, 50, paint);

    //Same Image  (file, bitmap, image_type, quality)
    SkImageEncoder::EncodeFile(path.c_str(), bitmap, SkImageEncoder::kPNG_Type, 0);

    return 0;
}
