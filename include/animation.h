/* Eya Sfar, Amal Bouakez, Sarra Ben Rejeb
 * Copyright (c) 2018 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2_gfxPrimitives.h>
#include<SDL_mixer.h>

#include "utils.h"
#include "hero.h"
#include "background.h"
#include "fire.h"
#include "spikes.h"


#define HERO_IMG       "assets/hero.png"
#define HERO_SPEED     250
#define HERO_MARGIN    20

#define FIRE_IMG       "assets/fire.png"
#define FIRE_SPEED     200
#define FIRE_MARGIN    0

#define SPIKES_IMG     "assets/spikes.png"
#define SPIKES_SPEED   250
#define SPIKES_MARGIN  0

#define NIGHT_IMG      "assets/starrynight.jpg"
#define NIGHT_SPEED    200

struct Animation
{
    // Animation screen dimensions
    int width;
    int height;

    // Animation renderer
    SDL_Renderer *renderer;

    // Background and Hero
    Background background;
    Hero hero;
    Fire fire;
    Spikes spikes;

    int score;
    bool gameover;
};
typedef struct Animation Animation;


bool Animation_start(SDL_Renderer *renderer, int width, int height);

bool Animation_load(Animation *animation);
void Animation_destroy(Animation *animation);

bool Animation_handleEvent(Animation *animation, SDL_Event *e);
void Animation_update(Animation *animation, int framerate);
void Animation_render(Animation *animation);

#endif // ANIMATION_H
