#pragma once

class MouseClickListener {
public:
    virtual void OnMouseDown() {};
    virtual void OnMouseUp() {};
    virtual void OnMouseReleased() {};
    virtual ~MouseClickListener() {};
};