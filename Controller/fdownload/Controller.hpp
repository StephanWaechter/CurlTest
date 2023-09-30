#pragma once
#include <swaechter/Observable.hpp>

namespace fdownload
{
	class Controller
	{
	public:
		swaechter::Observable<int> Counter;
	};
}