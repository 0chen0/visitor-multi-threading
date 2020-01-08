#ifndef RCCV_base_noncopyable_HPP
#define RCCV_base_noncopyable_HPP

namespace rccv
{

class noncopyable
{
public:
	noncopyable(const noncopyable&) = delete;
	void operator=(const noncopyable&) = delete;

protected:
	noncopyable() = default;
	~noncopyable() = default;

};

} //namespace rccv


#endif //RCCV_base_noncopyable_HPP