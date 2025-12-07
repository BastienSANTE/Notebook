<!DOCTYPE html>
<html>
<head>
<style>
 .math {
font-style: normal;
	}
.frac{
  margin-left:.1em;margin-right:.1em;
  vertical-align:center;
  text-align:center;
}
.num {
  padding:0 .1em;
  border-bottom: .1em solid;
}

.den{vertical-align:top;}
.math .stack{display:inline-block;
    vertical-align:middle;
    line-height:.95}
.math .stack .sign{display:block;font-size:2em}
.math .stack sub{display:block;text-align:center}
.math .stack sup{display:block;text-align:center}

.int{display:inline-block; vertical-align:-40%;position:relative;text-align:left;}
.int .sg{display:inline-block;font-size:260%;line-height:1.4;margin-top:-.2em;
  transform: scaleX(.7) skew(-12deg);
  -ms-transform: scaleX(.7) skew(-10deg); /* IE 9 */
  -webkit-transform: scaleX(.8) skew(-14deg); /* Safari and Chrome */
  -o-transform: scaleX(.7) skew(-10deg); /* Opera */
  -moz-transform: scaleX(.6) skew(-10deg); /* Firefox */
}
.int sub{font-size:.7em;position:absolute;bottom:0;left:.7em}
.int sup{font-size:.7em;position:absolute;top:0;left:1.65em}

</style>
</head>
<body>

<span class="math">3<i>x</i><sup>2</sup>+2<i>y</i>=27</span>

<div class="math ct"><i>f</i>(<i>x</i>) = 3<i>x</i> &minus; 2</div>

<div>
  <span class="math">e<sup>2<i>x</i>+1</sup>(<i>x</i><sup>2</sup> + 2) = 
  3<i>x</i> + 2 </span>
  <span class="math">⇔</span><br/>

  <span class="math">e<sup>2<i>x</i>+1</sup>(<i>x</i><sup>2</sup> + 2)
    <span> = 3<i>x</i> + 2</span></span>
</div>

<div class="math">
<table class="frac">
<tr><td class="num">1</td></tr>
<tr><td class="den">1</td></tr>
</table>
</div>

<span class="math">
  <i>S</i> = 
  <span class="stack">
    <sup><i>n</i></sup>
    <span class="sign">&sum;</span>
    <sub><i>k</i>=0</sub>
  </span>
  <i>q</i><sup><i>k</i></sup> 
  =
  <span class="frac">
    <span class="num">1 − <i>q</i><sup><i>n</i>+1</sup>
    </span><span class="fracbar">/</span>
    <span class="den">1 − <i>q</i></span>
  </span>
</span>

Le gradient d'une fonction 
<span class="math"><i>f</i> : 
<span class="Rset">R</span> <sup>2</sup> &rarr; <span class="Rset">R</span> 
</span> est 
<span class="math">
  <span class="vect">&nabla;</span><i>f</i>=
  <span class="matrix">
    <span class="row">
      <span class="aij">
	   <span class="frac">
          <span class="num">&part;<i>f</i></span>
          <span class="fracbar">/</span>
          <span class="den">&part;<i>x</i></span>
        </span>
      </span>
    </span>
    <span class="row">
      <span class="aij">
	      <span class="frac">
            <span class="num">&part;<i>f</i></span>
            <span class="fracbar">/</span>
            <span class="den">&part;<i>y</i></span>
          </span>
      </span>
    </span>
  </span>
</span>


<span class="math ct">Δ<i>f</i>=
  <span class="frac">
    <span class="num">&part;<sup>2</sup><i>f</i></span>
    <span class='fracbar'>/</span>
    <span class="den">&part;<i>x</i><sup>2</sup></span>
  </span>
  +
  <span class="frac">
    <span class="num">&part;<sup>2</sup><i>f</i></span>
    <span class='fracbar'>/</span>
    <span class="den">&part;<i>y</i><sup>2</sup></span>
  </span>
</span>

</body>

</html>
