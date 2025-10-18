module dragon2_f_api
  use, intrinsic :: iso_c_binding
  implicit none
contains
  ! Suma simple para probar el enlace
  function f_add(a, b) result(r) bind(C, name="dragon2_f_add")
    real(c_double), value :: a, b
    real(c_double)        :: r
    r = a + b
  end function
end module
