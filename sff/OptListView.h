#pragma once

namespace sff {
	ref class OptListView : public System::Windows::Forms::ListView
	{
	public:
		OptListView() {
			SetStyle(System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer, true);
		}
	};
}
