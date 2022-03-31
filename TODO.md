# Before evaluations
* Uncomment "static" from header so STATIC works.
* Push to intra, instead of my personal GitHub.
* Make test clone repo.
* paco and other tests (at least ft_printf_tester)
* norminette_color $(git ls-tree --name-only HEAD -r | egrep -v -e '^minilibx' -e '^tests/' | egrep '\.[ch]')
* DONE!

# At some later point
* Add tests for every combination of flags.
* Try to figure out the exact rules for multi-line variable tabbing, cause it isn't always 2!
  Then once I know how that works, consider applying those same rules to multi-line function argument tabbing.
* Consistently use && on the line *before* or *at the start of* the line of a second argument.
