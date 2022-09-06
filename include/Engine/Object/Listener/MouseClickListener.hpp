#pragma once

class MouseClickListener {
public:
    virtual void OnMouseDown() = 0;
    virtual void OnMouseUp() = 0;
    virtual void OnMouseReleased() = 0;
    virtual ~MouseClickListener() {};
};