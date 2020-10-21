class WindowCartesian: public RenderWindow {
private:
    Transform _flip_y_axis_transform_;

public:
    template<typename... Args>
    WindowCartesian(Args... args): RenderWindow(args...) {
        Transformable transformation;
        transformation.setOrigin(0, RenderWindow::getSize().y);
        transformation.setScale (1, -1);

        _flip_y_axis_transform_ = transformation.getTransform();
    }

    template<typename... Args>
    void draw(Args... args) {
        RenderWindow::draw(args..., _flip_y_axis_transform_);
    }
};
