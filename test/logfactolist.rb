require 'bigdecimal'
require 'bigdecimal/math'

def fact(n)
  return 1 if n == 0
  n * fact(n-1)
end

def logfacto(i, prec)
  BigMath.log(fact(i), prec).round(prec)
end


# IEEE-754 FP single precision
enum = (0..254).enum_for(:each)
list = <<-End
// for IEEE-754 FP single precision
static const float lf[] =
{
End
loop do
  temp = ""
  temp << logfacto(enum.next, 6).to_s << ",\n"
  list.concat "\t", temp
end
list << "} ;\n"
IO.write("lf_single.h", list)

# IEEE-754 FP double precision
enum = (0..254).enum_for(:each)
list = <<-End
// for IEEE-754 FP double precision
static const double lf[] =
{
End
loop do
  temp = ""
  temp << logfacto(enum.next, 15).to_s << ",\n"
  list.concat "\t", temp
end
list << "} ;\n"
IO.write("lf_double.h", list)

# IEEE-754 FP extend double precision
enum = (0..254).enum_for(:each)
list = <<-End
// for IEEE-754 FP extend double precision
static const long double lf[] =
{
End
loop do
  temp = ""
  temp << logfacto(enum.next, 18).to_s << ",\n"
  list.concat "\t", temp
end
list << "} ;\n"
IO.write("lf_extend.h", list)

# IEEE-754 FP quad precision
enum = (0..254).enum_for(:each)
list = <<-End
// for IEEE-754 FP quad precision
static const long double lf[] =
{
End
loop do
  temp = ""
  temp << logfacto(enum.next, 33).to_s << ",\n"
  list.concat "\t", temp
end
list << "} ;\n"
IO.write("lf_quad.h", list)


