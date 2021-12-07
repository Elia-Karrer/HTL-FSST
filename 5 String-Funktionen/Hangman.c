/**
    Simple hangman game
    All rights reserved
    Elia Karrer, 2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

#define CHEAT 0

void gameover();
void gamewon();
void lower(char *);

typedef struct Word word;
struct Word {
    char str[16];
};

int main()
{
    const char divider = '.';
    const char * list = "abruptly.absurd.abyss.affix.askew.avenue.awkward.axiom.azure.bagpipes.bandwagon.banjo.bayou.beekeeper.bikini.blitz.blizzard.boggle.bookworm.boxcar.boxful.buckaroo.buffalo.buffoon.buxom.buzzard.buzzing.buzzwords.caliph.cobweb.cockiness.croquet.crypt.curacao.cycle.daiquiri.dirndl.disavow.dizzying.duplex.dwarves.embezzle.equip.espionage.euouae.exodus.faking.fishhook.fixable.fjord.flapjack.flopping.fluffiness.flyby.foxglove.frazzled.frizzled.fuchsia.funny.gabby.galaxy.galvanize.gazebo.giaour.gizmo.glowworm.glyph.gnarly.gnostic.gossip.grogginess.haiku.haphazard.hyphen.iatrogenic.icebox.injury.ivory.ivy.jackpot.jaundice.jawbreaker.jaywalk.jazziest.jazzy.jelly.jigsaw.jinx.jiujitsu.jockey.jogging.joking.jovial.joyful.juicy.jukebox.jumbo.kayak.kazoo.keyhole.khaki.kilobyte.kiosk.kitsch.kiwifruit.klutz.knapsack.larynx.lengths.lucky.luxury.lymph.marquis.matrix.megahertz.microwave.mnemonic.mystify.naphtha.nightclub.nowadays.numbskull.nymph.onyx.ovary.oxidize.oxygen.pajama.peekaboo.phlegm.pixel.pizazz.pneumonia.polka.pshaw.psyche.puppy.puzzling.quartz.queue.quips.quixotic.quiz.quizzes.quorum.razzmatazz.rhubarb.rhythm.rickshaw.schnapps.scratch.shiv.snazzy.sphinx.spritz.squawk.staff.strength.strengths.stretch.stronghold.stymied.subway.swivel.syndrome.thriftless.thumbscrew.topaz.transcript.transgress.transplant.triphthong.twelfth.twelfths.unknown.unworthy.unzip.uptown.vaporize.vixen.vodka.voodoo.vortex.voyeurism.walkway.waltz.wave.wavy.waxy.wellspring.wheezy.whiskey.whizzing.whomever.wimpy.witchcraft.wizard.woozy.wristwatch.wyvern.xylophone.yachtsman.yippee.yoked.youthful.yummy.zephyr.zigzag.zigzagging.zilch.zipper.zodiac.zombie.";

    srand(time(0));
    int listlen = strlen(list);
    int wordsinlist = 0;
    int c = 0, cc = 0;
    int i, j;
    int level = 1;
    int ret = 0;
    char input;
    word currentguess;

    ///Create separate strings for words
    for(i = 0; i < listlen; i++)
        if(list[i] == divider)
            wordsinlist++;
    word words[wordsinlist];

    //c  = current word
    //cc = (local) current words char
    //i  = (global) count in long string
    for(i = 0; i < listlen; i++)
    {
        if(list[i] == divider)
        {
            words[c].str[cc] = '\0';
            c++;
            cc = 0;
        }
        else
        {
            words[c].str[cc] = list[i];
            cc++;
        }
    }

    ///MAIN GAME
    while(1)
    {
        word currentword = words[rand() % wordsinlist];
        for(i = 0; i < 16; i++)
            currentguess.str[i] = '_';
        currentguess.str[strlen(currentword.str)] = '\0';

        for(i = 0; i < 16; i++)
        {
            system("cls");
            printf("Level %d:\n\n%s  %d trys left\n\n%s%s", level, currentguess.str, 16-i, (CHEAT == 1) ? "Solution: " : "" , (CHEAT == 1) ? currentword.str : "");
            if(strcmp(currentguess.str, currentword.str) == 0) break;

            input = getch();
            lower(&input);
            if(strchr(currentword.str, input) != NULL)
            {
                for(j = 0; currentguess.str[j] != '\0'; j++)
                    if(currentword.str[j] == input)
                        currentguess.str[j] = input;
            }

            if(i == 15)
                ret = 1;
        }

        if(ret == 1)
            gameover();
        if(level == 8)
            gamewon();
        if(ret == 1 || level == 8)
            break;
        level++;
    }

}

void gameover()
{
    system("color c & cls");
    printf("GAME OVER!\n");
}

void gamewon()
{
    system("color a & cls");
    printf("GAME WON!\n");
}

void lower(char *c)
{
    if(*c > 64 && *c < (64+26))
        *c += 32;
}
