#ifndef SCROLLBOX_H
#define SCROLLBOX_H

#include "frame.h"

class ScrollBox{
	public:
		ScrollBox();
		~ScrollBox();

		ScrollBox& operator=(const ScrollBox &source);

		friend class Frame;
	private:
};

#endif