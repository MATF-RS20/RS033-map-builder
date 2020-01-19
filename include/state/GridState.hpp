#ifndef MAP_MAKER_GRIDSTATE_HPP
#define MAP_MAKER_GRIDSTATE_HPP

#include <QtCore/QRectF>
#include <QtCore/QObject>

namespace map_builder::state
{
    /**
     * TODO: add things like return to max zoom and so on
     */
    class GridState : public QObject
    {
        Q_OBJECT

    public:

        static constexpr int distanceBetweenCells = 150;
        static constexpr float zoom_out_factor{1.01};
        static constexpr float zoom_in_factor{1/zoom_out_factor};

        GridState(int w, int h, QObject *parent = nullptr);

        inline int width() const
        {
            return mWidth;
        }

        inline int height() const
        {
            return mHeight;
        }

        inline const QRectF& sceneRect()
        {
            return mSceneRect;
        }

        /**
         *
         * @param factor - how much to  zoom in/ out. If factor is in interval (0, 1) it will zoom in
         * and if it is in interval (1, +inf) it will zoom out
         */
        void zoom(float factor);
        /**
         *
         * @param factor  - how much to  zoom in/ out. If factor is in interval (0, 1) it will zoom in
         * and if it is in interval (1, +inf) it will zoom out
         * @param point_to_zoom_in - zoom in to this point. Given point will be the center of zoomed area.
         */
        void zoom(float factor, const QPointF &point_to_zoom_in);

        /**
         *
         * @param move_vector  - vector in witch direction and by how much to move center of the scene rect
         */
        void moveSceneRect(const QVector2D &move_vector);

    signals:
        void sceneRectChanged(const QRectF &scene_rect);

    private:
        int mWidth;
        int mHeight;
        QRectF mSceneRect;
    };
}
#endif //MAP_MAKER_GRIDCONTROLLER_HPP
