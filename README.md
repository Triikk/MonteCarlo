# Monte Carlo methods
The [Monte Carlo methods](https://en.wikipedia.org/wiki/Monte_Carlo_method) (or experiments) are a broad class of computational algorithms that rely on repeated random sampling.

## How it works
1) Generate random x,y between -1 and +1
2) If x**2 + y**2 <= 1, the point generated is inside the circle, otherwise it is outside ([Pythagorean trigonometric identity](https://en.wikipedia.org/wiki/Pythagorean_trigonometric_identity))
3) Draw the point and increment one of the two counters
4) count_in / count_total is pi/4 since we are considering the top right piece, so we multiply by 4
