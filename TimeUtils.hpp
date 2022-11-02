#pragma once

namespace TimeUtils {
	/*
		set current delta time to zero
	*/
	void ResetDelta();
	
	/*
		get time elapsed since last frame (in seconds)
	*/
	float GetDelta();
}