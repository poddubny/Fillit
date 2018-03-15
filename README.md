# Fillit
The purpose is to make the smallest possible "square" (which can contain holes) with a given list of tetriminos, but the disposition must be as such that it returns the first possible solution when placing them recursively from the top left.

# Compiling
Run <code>make</code>, an executable called <code>fillit</code> should compile directly. Please submit an issue if you run into any.

# Usage
<code>./fillit [file]</code>

Example:

<pre><code>~ ./fillit ../samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
</code></pre>
