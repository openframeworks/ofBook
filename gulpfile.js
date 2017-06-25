const gulp = require("gulp");
const browserSync = require("browser-sync").create();
const sass = require("gulp-sass");
const autoprefixer  = require("gulp-autoprefixer");
const sourcemaps = require("gulp-sourcemaps");
const plumber = require("gulp-plumber");

// Static Server + watching scss/html files
gulp.task("serve", function() {
    browserSync.init({
        server: "./output/webBook",
        directory: true,
        startPath: "/chapters"
    });
});

// Compile sass into CSS & auto-inject into browsers
gulp.task("sass", function() {
    return gulp.src("static/style/**/*.+(scss|sass)")
        .pipe(plumber()) // Don't crash on error
        .pipe(sourcemaps.init())
            .pipe(sass({outputStyle: "compressed"}))
            .pipe(autoprefixer({
                browsers: ["last 2 versions"],
                cascade: true
            }))
        .pipe(sourcemaps.write())
        .pipe(gulp.dest("output/webBook/style/"))
        .pipe(browserSync.stream());
});

// Copy static files other than CSS
gulp.task("copy", function() {
    return gulp.src(
            ["static/vendor/**/*.*", "static/javascript/**/*.*", "static/images/**/*.*"], 
            {base: "static"}
        )
        .pipe(gulp.dest("output/webBook/"))
});

gulp.task("watch", function () {
    gulp.watch("static/style/**/*", ["sass"]);
    gulp.watch(
        ["static/vendor/**/*.*", "static/javascript/**/*.*", "static/images/**/*.*"], 
        ["copy"]
    );
    gulp.watch("output/webBook/**").on("change", browserSync.reload);
});

gulp.task("default", ["serve", "sass", "copy", "watch"]);