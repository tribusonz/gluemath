def round(x)
  sign = 0
  if x.nan? || x.infinite? then return x
  elsif x.positive?
    if (x < 1) then return x < 0.5 ? 0.0 : 1.0; end
  elsif x.negative?
    if (x > -1) then return x < -0.5 ? -1.0 : -0.0; end
    sign = 1; x = x.abs
  end

  frac, base_exp = Math.frexp(x)
  frac = (frac - 0.5) * 2
  base_exp -= 1

  s = 0.0; t = 1.0 / 2

  base_exp.times do |i|
    if (frac >= (s + t)) then s += t; end
    if (s == frac) then break; end
    t /= 2
  end
  eq = Math.ldexp(1.0, base_exp)
  ip = eq + eq * s
  if sign == 0
    return (frac - s) * eq < 0.5 ? ip : ip + 1
  elsif sign == 1
    return (frac - s) * eq <= 0.5 ? -ip : -ip - 1
  end
end
