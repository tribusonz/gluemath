# frozen_string_literal: true

module Math
  LOG2 = log(2)
  
  def expxt(x, t)
    a = x * t; b = 1.0; c = 1.0; s = 1.0;
    loop do
      b = b * a / c;
      unless b > Float::EPSILON; break; end
      s = s + b;
      c = c + 1
    end
    s
  end
  
  def exp(x) # Overridden
    floorx = x.floor
    vfra = x - floorx
    vexp = E ** floorx
    if (vfra == 0.0) then return vexp.to_f; end
    vexp * expxt(vfra, 1)
  end

  def exp2(x)
    floorx = x.floor
    vfra = x - floorx
    vexp = 2 ** floorx
    if (vfra == 0.0) then return vexp.to_f; end
    vexp * expxt(vfra, LOG2)
  end
  
  protected :expxt
  module_function :exp, :exp2, :expxt
end

