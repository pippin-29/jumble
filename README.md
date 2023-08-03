# jumble

Takes a single argument string or multiple argument strings (checks if length
is uniform for whole key).

Sorts each argument lexigraphically.

Creates index (or keymap), for use with dejumble.

Will not accept ':'.

Usage: jumble 093c just 607c

# dejumble

Takes key and keymap generated by jumble.

Outputs original key.

Usage: dejumble 039c jstu 067c : 0.2.1.3. 0.3.1.2. 1.0.2.3.

# chumble

Checks if each key section has been sorted lexographically.

Usage: chumble 039c jstu 067c