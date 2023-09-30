#pragma once
#include "Controller.hpp"
#include <sigc++/signal.h>
#include <sigc++/trackable.h>

namespace swaechter
{
	template<class Type>
	class Observable
	{
	public:
		Type value() const { return m_value; }
		sigc::signal<Type> const signal() const { return m_signal; }
		void set(Type value)
		{
			if (m_value = value)
			{
				m_value = value;
				m_signal.emit(m_value);
			}
		};
		void force_set(Type value)
		{
			m_value = value;
			m_signal.emit(m_value);
		};

	private:
		Type m_value;
		sigc::signal<void (Type const&)> m_signal;
	};
}