# Desk Buddy Build Journal

## Jul 14, 2026, 11:06 AM

I wired up all the components to the Esp32 and began writing the code. I used online tutorials to help initialise the oled display and then managed to create my own eyes. At first I started with just 2 circles. But to make it more alive I added a pupil to the eyes. However it was still lifeless. So I used the random number generator to randomly generate the pupils x and y coordinates and placed this in the loop to make it seem like the eyes were moving. This worked well but while looking on youtube I came across a much better set of eyes that someone created and installed their library and am now adding these eyes instead.

---

## Jul 14, 2026, 12:52 PM

So I tried using cooler robot eyes but I couldn't get it to work and it seemed past my capabilities so I moved back to my version. I programmed the display to sweat when temp from dht11 increased above 25 and no I'm trying to get it to sleep under low light but I might have just added a blinking feature by accident :)

---

## Jul 14, 2026, 2:20 PM

I decided to remove the blinking feature because it was messing with the other parts. I am now trying to just touch up on the animations and reaction to sensors to finish off

---

## Jul 22, 2026, 9:03 PM

I decided to add an RGB LED as an output. I'm thinking it will be green when the buddy wakes up and then when its hot/sweating it will turn red.