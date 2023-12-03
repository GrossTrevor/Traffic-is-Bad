const map = L.map('map').setView([37.8, -96], 4);

const tiles = L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);

// control that shows state info on hover
const info = L.control();

info.onAdd = function (map) {
    this._div = L.DomUtil.create('div', 'info');
    this.update();
    return this._div;
};

info.update = function (props) {
    const contents = props ? `<b>${props.COUNTY}, ${props.STATE}</b><br />Average crash severity: ${props.SEVERITY}` : 'Hover over a county';
    this._div.innerHTML = `<h4>Information Panel</h4>${contents}`;
};

info.addTo(map);

function filterMap(prop) {
    if (prop == 'SEVERITY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.SEVERITY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'CROSSING') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.CROSSING))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'JUNCTION') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.JUNCTION))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'SIGNAL') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.SIGNAL))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'DAY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.DAY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'NIGHT') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.NIGHT))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'POOR_VISIBILITY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.POOR_VISIBILITY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WFAIR') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.WFAIR))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WCLOUDY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.WCLOUDY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WFOG') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.WFOG))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WRAIN') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.WRAIN))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WSNOW') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColor(parseInt(feature.properties.WSNOW))
                };
            },
            onEachFeature
        }).addTo(map);
    }
 }


// get color depending on population density value
function getColor(d) {
    return d > 3.9 ? '#c70505' :
           d > 3.5 ? '#c73605' :
           d > 3 ? '#c79605' :
           d > 2.5 ? '#c7c705' :
           d > 2 ? '#96c705' :
           d > 1.5 ? '#66c705' :
           d > 1 ? '#05c705' : '#D3D3D3';
}

function highlightFeature(e) {
    const layer = e.target;

    layer.setStyle({
        weight: 3,
        color: '#666',
        dashArray: '',
        fillOpacity: 0.7
    });

    layer.bringToFront();

    info.update(layer.feature.properties);
}

/* global statesData */
var geojson = L.geoJson(county_data, {
    style: function (feature) {
        return {
            weight: 1,
            opacity: 1,
            color: 'white',
            dashArray: '3',
            fillOpacity: 0.7,
            fillColor: getColor(parseInt(feature.properties.SEVERITY)) };
    },
    onEachFeature
}).addTo(map);

function resetHighlight(e) {
    geojson.resetStyle(e.target);
    info.update();
}

function zoomToFeature(e) {
    map.fitBounds(e.target.getBounds());
}

function onEachFeature(feature, layer) {
    layer.on({
        mouseover: highlightFeature,
        mouseout: resetHighlight,
        click: zoomToFeature
    });
}

map.attributionControl.addAttribution('Crash data CC BY-NC-SA 4.0; <a href="https://www.kaggle.com/datasets/sobhanmoosavi/us-accidents/data">Sobhan Moosavi</a>');

function resetMap() {
    map.setView([37.8, -96], 4);
}

//const legend = L.control({ position: 'bottomright' });

//legend.onAdd = function (map) {

//    const div = L.DomUtil.create('div', 'info legend');
//    const grades = [0, 10, 20, 50, 100, 200, 500, 1000];
//    const labels = [];
//    let from, to;

//    for (let i = 0; i < grades.length; i++) {
//        from = grades[i];
//        to = grades[i + 1];

//        labels.push(`<i style="background:${getColor(from + 1)}"></i> ${from}${to ? `&ndash;${to}` : '+'}`);
//    }

//    div.innerHTML = labels.join('<br>');
//    return div;
//};

//legend.addTo(map);