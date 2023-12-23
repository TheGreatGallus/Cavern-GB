# Cavern (GB)
 
Source code for Cavern, a Game Boy game. This version is the version that was submitted to Metroidvania Month 9 game jam on itch.io back in 2020. It can be found here for playing a web build or downloading your own copy. (https://thegreatgallus.itch.io/cavern-mvm-9)

This game uses ZGB (https://github.com/Zal0/ZGB) as an engine. The source here contains a modified verion of ZGB from back in 2020, so that the game builds and plays as expected with the additional features (mainly, the animated tiles).

As it currently is, this version contains a few bugs as it is the original MVM9 Jam version of the game. 

- Selecting "Continue" on your first play will cause the game to crash. Just reload and select "New Game" instead.
- Selecting "New Game" instantly overwrites your save file
- Using the "Shrink" ability against wall that is only one tile thick will send you through the wall, likely to the debug room. This can be a softlock, so mind this.
- Some of the pointers for the health upgrades were messed up somewhere, so it is possible that collecting them in a certain order will cause others to despawn. It is possible to get them all, I don't know which ones were broken at the time I made this.
- The "Double Jump" has an interesting (but not negative for the player) bug. Just mentioning it, you can figure it out for yourself
- Not necessarily a bug, but there are some places with significant slowdown. I have ideas to fix this, just didn't at the time.

I may someday return to this project to clean it up and add some improvement. It's been over three years since I last worked on it, so no idea when that would be. But hopefully someone will find this interesting or insightful or entertaining.

Enjoy.
